import React from "react";
import PropTypes from "prop-types";
import "./RoboSpec.css";

function RoboSpec({specs}){ 
  return (
    <aside className="robot-spec">
      <h3>Robo Spec</h3>
      <ul>
        {specs.map((spec, index) => (
          <li key={index} className="spec-item">
            <span className="material-symbols-outlined spec-icon">{spec.icon}</span>
            <span className="spec-name">{spec.name}</span>
            <span className="spec-quantity">{spec.quantity} pcs</span>
            <span className="spec-description">{spec.description}</span>
          </li>))
        }
      </ul>
    </aside>
  );
};

RoboSpec.propTypes = {
  specs: PropTypes.arrayOf(
    PropTypes.shape({
      icon: PropTypes.string.isRequired,  // 'icon' should be a string
      name: PropTypes.string.isRequired,  // 'name' should be a string
      quantity: PropTypes.oneOfType([     // 'quantity' should be a number or a string
        PropTypes.number,
        PropTypes.string,
      ]),  
      description: PropTypes.string.isRequired,  // 'description' should be a string
    })
  ).isRequired  // 'specs' should be an array of objects and is required
};

export default RoboSpec;
