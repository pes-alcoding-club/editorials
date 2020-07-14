import fs from 'fs';
import path from 'path';
import remark from 'remark';
import html from 'remark-html';
import matter from 'gray-matter';

const dbPath = path.join(process.cwd(), 'editorials', 'db.json');
const editorialFilesPath = path.join(process.cwd(), 'editorials', 'problems');

export function getDbData() {
	let dbFileData = fs.readFileSync(dbPath);
	let db = JSON.parse(dbFileData);
	return db;
}

const db = getDbData();

export async function getEditorialData(id) {
	const reqPath = path.join(editorialFilesPath, id);

	const fileNames = fs.readdirSync(reqPath); 

	let editorialFileContent = fs.readFileSync(path.join(reqPath, 'editorial.md'), 'utf8');
	let editorial = matter(editorialFileContent);
	editorial = await remark().use(html).process(editorial.content);
	editorial = editorial.toString();

	const editorialObj = { editorial, solutions: {}, problemData: db[id] };

	fileNames.forEach( fileName => {
		if(fileName !== 'editorial.md'){
			let language = fileName.split('.')[1];
			let solution = fs.readFileSync(path.join(reqPath, fileName), 'utf8');
			editorialObj.solutions[language] = solution;
		}
	})
	
	return editorialObj;
}

export function getAllProblemIds() {
	const db = getDbData();
	return Object.keys(db).map(key => {
		return {
			params: {
				id: key
			}
		}
	})
}