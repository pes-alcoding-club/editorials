const Navbar = () => (
    <nav className="navbar navbar-expand-lg navbar-light bg-light">
        <a className="nav-link" href={`${process.env.ASSET_PREFIX}/`}>
            <img src="/logo.jpg" width="80" height="70" alt="the alcoding club logo" />
        </a>
        <a className="navbar-brand" href="#">Editorials</a>
        <button className="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarColor03" aria-controls="navbarColor03" aria-expanded="false" aria-label="Toggle navigation">
            <span className="navbar-toggler-icon"></span>
        </button>

        <div className="collapse navbar-collapse" id="navbarColor03">
            <ul className="navbar-nav mr-auto">
                <li className="nav-item active">
                    <a className="nav-link" href={`${process.env.ASSET_PREFIX}/`}>Home <span className="sr-only">(current)</span></a>
                </li>
            </ul>
            {/* <form className="form-inline my-2 my-lg-0">
                <input className="form-control mr-sm-2" type="text" placeholder="Search"/>
                <button className="btn btn-secondary my-2 my-sm-0" type="submit">Search</button>
            </form> */}
        </div>
    </nav>
);


export default Navbar;