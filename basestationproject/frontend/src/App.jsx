import Header from './Header.jsx'
import Footer from './Footer.jsx'
import KangaConnection from './pages/index/KangaConnection.jsx';
import DeviceDetails from './pages/index/DeviceDetails.jsx';
import QuickOverview from './pages/index/QuickOverview.jsx';
import RoboSpec from './pages/index/RoboSpec.jsx';
import ControlCommandLogHistory from './pages/control_command/LogHistory.jsx';
import NLISection from './pages/control_command/NLISection.jsx';
import MapAndControls from './pages/control_command/MapAndControls.jsx';
import DataGraph from './pages/data_sensors/DataGraph.jsx'
import DataLogHistory from './pages/data_sensors/LogHistory.jsx'
import { useRoutes } from 'react-router-dom';

import React from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import "./App.css";
import Dashboard from "./pages/Dashboard";

function AppRoutes() {
  const routes = useRoutes([
    {path: "/", element: <Dashboard />},
    {path: "/arm-control", element: <ArmControl />},
    {path: "/settings", element: <Settings />},
    {path: "/about", element: <About />},
    {path: "/KangaConnection", element: <KangaConnection />},
    {path: "/DeviceDetails", element: <DeviceDetails />},
    {path: "/QuickOverview", element: <QuickOverview />},
    {path: "/RoboSpec", element: <RoboSpec />},
    {path: "/ControlCommandLogHistory", element: <ControlCommandLogHistory />},
    {path: "/NLISection", element: <NLISection />},
    {path: "/MapAndControls", element: <MapAndControls />},
    {path: "/DataGraph", element: <DataGraph />},
    {path: "/DataLogHistory", element: <DataLogHistory />}
  ])
}
function App() {
  return (
   <div>
    <Routes>
      <Route path='/HelloWorld' element = { <HelloWorld /> } />
    </Routes>
   </div>
  );
}

export default App;
