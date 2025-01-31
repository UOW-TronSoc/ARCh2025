import React from "react";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import './App.css'
import Dashboard from "./pages/Dashboard";
import JoystickControl from "./pages/JoystickController";
import CameraControl from './pages/CameraControl';
import CameraFeed from './pages/CameraFeed';

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Dashboard />} />
        <Route path="/JoystickControl" element={<JoystickControl />} />
        <Route path="/CameraControl" element={<CameraControl />} />
        <Route path="/CameraFeed" element={<CameraFeed />} />
        
      </Routes>
    </BrowserRouter>
  );
}

export default App;
