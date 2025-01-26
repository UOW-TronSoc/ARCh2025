import React, {useState} from "react";
import "./DataGraph.css";

function DataGraph() {
  const [activeCategory, setActiveCategory] = useState("SER");

  const categories = ["POP", "GLU", "SER", "DOP", "TON"];

  const handleCategoryClick = (category) => {
    setActiveCategory(category);
    // Add additional functionality for category change here if needed
  };

  return ( 
    <div className="data-graph">
      <h3 className="text-white">Categories:</h3>
      <div className="categories">
        {categories.map((category, index) => (
          <button
            key={index}
            className={`category-btn ${activeCategory === category ? "active" : ""}`}
            onClick={() => handleCategoryClick(category)}
          >
            {category}
          </button>
        ))}
      </div>
      <div className="graph-container">
        <canvas id="data-graph"></canvas>
    </div>
    <button className="btn download-btn">Download</button>
  </div>
  );
};

export default DataGraph;