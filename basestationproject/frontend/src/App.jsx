import React from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import Layout from "./components/Layout"; // Create a reusable layout component
import Dashboard from "./pages/Dashboard";
import NotFound from "./pages/NotFound";

function App() {
  return (
    <Router>
      <Routes>
        {/* Default route with layout */}
        <Route path="/" element={<Layout />}>
          <Route index element={<Dashboard />} /> {/* Default route */}
          {/* Add more child routes for other pages as needed */}
        </Route>
        {/* Catch-all route for 404 */}
        <Route path="*" element={<NotFound />} />
      </Routes>
    </Router>
  );
}

export default App;
