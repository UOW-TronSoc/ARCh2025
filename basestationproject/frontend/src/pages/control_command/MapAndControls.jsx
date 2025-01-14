
function MapAndControls() {
  return (
    <div className="map-controls">
      <div className="map">
        <p>Map</p>
      </div>
      <div className="control-panel">
        <select>
          <option>Choose an option</option>
          <option>Option 1</option>
          <option>Option 2</option>
          <option>Option 3</option>
        </select>
        <div className="control-buttons">
          <button className="start-btn">Start</button>
          <button className="stop-btn">Stop</button>
        </div>
      </div>
    </div>
  );
}

export default MapAndControls;
