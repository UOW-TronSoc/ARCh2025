import React from "react";
import { BrowserRouter } from "react-router-dom";
import { useRoutes } from "react-router-dom";
import './App.css'
import Dashboard from "./pages/Dashboard";
// import ArmControl from "./pages/ArmControl/arm";
// import Settings from "./pages/Settings/settings";
// import About from "./pages/About/about";s
// import Navbar from "./components/ui/Navbar/Navbar";

function AppRoutes() {
  const routes = useRoutes([
    { path: "/", element: <Dashboard /> },
    // { path: "/arm-control", element: <ArmControl /> },
    // { path: "/settings", element: <Settings /> },
    // { path: "/about", element: <About /> },
  ]);
  return routes;
}

function App() {
  return (
    <div>
      <Routes>
        <Route path='/HelloWorld' element = {
            <HelloWorld />
          }
        />
        </Routes>
    </div>
  );
}

export default App;
