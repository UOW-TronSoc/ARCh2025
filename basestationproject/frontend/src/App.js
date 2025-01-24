import React from "react";
import { BrowserRouter, Routes, Route } from "react-router-dom";
import './App.css'
import Dashboard from "./pages/Dashboard";
import JoystickControl from "./pages/JoystickController";

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Dashboard />} />
        <Route path="/JoystickControl" element={<JoystickControl />} />
      </Routes>
    </BrowserRouter>
  );
}

export default App;
