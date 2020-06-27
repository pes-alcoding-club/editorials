import React from 'react';
import Layout from '../../components/Layout';
import { getAllProblemIds, getEditorialData } from '../../lib/problems';
import SyntaxHighlighter from 'react-syntax-highlighter';


export default class Editorial extends React.Component {
    constructor(props) {
        super(props);
        this.languages = {
            'cpp': 'C++',
            'c': 'C',
            'java': 'Java',
            'py': 'Python'
        }
        this.editorLanguages = {
            'cpp': 'cpp',
            'c': 'cpp',
            'java': 'java',
            'py': 'python'
        }
        this.state = {
            selectedLanguage: null
        }
        this.handleLanguageChange = this.handleLanguageChange.bind(this);
    }
    componentDidMount(){
        this.setState({
            selectedLanguage: Object.keys(this.props.editorialData.solutions)[0]
        })
    }

    handleLanguageChange(event){        
        const selectedLanguage = event.target.value;
        this.setState({
            selectedLanguage
        })
    }

    render() {
        let solutionCode = '';        
        if(this.state.selectedLanguage != null)
            solutionCode = this.props.editorialData.solutions[this.state.selectedLanguage];
        
        return (
            <Layout>
                <div className="jumbotron">
                    <h3>Editorial</h3>
                    <div dangerouslySetInnerHTML={{ __html: this.props.editorialData.editorial }} />
                </div>

                <select id="languageSelector" onChange={ this.handleLanguageChange }>
                    {
                        Object.keys(this.props.editorialData.solutions).map( lang => (
                            <option key={lang} value={lang}>{this.languages[lang]}</option>
                        ))
                    }
                </select>

                <SyntaxHighlighter language={this.editorLanguages[this.state.selectedLanguage]}>
                    { solutionCode }
                </SyntaxHighlighter>
            </Layout>
        );
    }    
};

export async function getStaticPaths() {
    const paths = getAllProblemIds();
    return {
        paths,
        fallback: false
    }
} 


export async function getStaticProps({ params }) {
    const editorialData = await getEditorialData(params.id);
    console.log(editorialData);
    return {
        props: {
            editorialData
        }
    }
}