import React, { useState } from 'react';
import 'react-bootstrap';
import './MapAndControls.css';

function ControlPanel({ options }) {
  const [selectedOption, setSelectedOption] = useState('');

  const handleChange = (event) => {
    setSelectedOption(event.target.value);
  };

  return (
    <div className="control-panel">
      <div className="mb-3">
        <label htmlFor="optionsSelect" className="form-label">
          Choose an option
        </label>
        <select
          id="optionsSelect"
          className="form-select"
          value={selectedOption}
          onChange={handleChange}
        >
          <option value="">Choose an option</option>
          {options.map((option, index) => (
            <option key={index} value={option.value}>
              {option.label}
            </option>
          ))}
        </select>
      </div>
      <div className="control-buttons">
        <button className="btn btn-primary me-2">Start</button>
        <button className="btn btn-danger">Stop</button>
      </div>
    </div>
  );
}

function MapAndControls() {
  // Dynamic options
  const options = [
    { label: 'Option 1', value: 'option1' },
    { label: 'Option 2', value: 'option2' },
    { label: 'Option 3', value: 'option3' },
  ];

  return (
    <div className="map-controls container mt-4">
      <div className="map mb-4">
        <p className="text-center">Map</p>
      </div>
      <ControlPanel options={options} />
    </div>
  );
}

export default MapAndControls;
