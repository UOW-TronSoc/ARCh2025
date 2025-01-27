import './data_sensors.css'

function DataGraph() {
    return (
      <div class="data-graph">
        <h3>Categories:</h3>
        <div class="categories">
            <button>POP</button>
            <button>GLU</button>
            <button class="active">SER</button>
            <button>DOP</button>
            <button>TON</button>
        </div>
        <div class="graph-container">
            <canvas id="data-graph"></canvas>
        </div>
        <button class="download-btn">Download</button>
      </div>
    );
  }
  
  export default DataGraph;
  