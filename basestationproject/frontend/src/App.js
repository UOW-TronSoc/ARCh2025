import React from "react";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import './App.css'
import Dashboard from "./pages/Dashboard";
import JoystickControl from "./pages/JoystickControl";
import CameraFeed from './pages/CameraFeed';
import ScienceDashboard from './pages/ScienceDashboard';

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Dashboard />} />
        <Route path="/JoystickControl" element={<JoystickControl />} />
        <Route path="/CameraFeed" element={<CameraFeed />} />
        <Route path="/ScienceDashboard" element={<ScienceDashboard />} />

        
        
      </Routes>
    </BrowserRouter>
  );
}

export default App;
