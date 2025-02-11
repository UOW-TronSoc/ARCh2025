import React from "react";
import PropTypes from "prop-types";
import "./KangaConnection.css";
function KangaConnection({name, isConnected, onConnect, onDisconnect}) {
  return (
    <div className="kanga-connection d-flex flex-column align-items-center">
      <span className="material-symbols-outlined" id="kanga-icon">
        smart_toy
      </span>
      <h2 className="device-name mb-3">{name}</h2>
      <div className="connect-buttons d-flex gap-2">
        <button className="connect-btn"
          disabled={isConnected}
          onClick={onConnect}>
        Connected
        </button>
        <button className="disconnect-btn btn btn-outline-danger" 
          disabled={!isConnected}
          onClick={onDisconnect}>
          Disconnect
        </button>
        <button className="btn btn-light mt-2">
          <span className="material-symbols-outlined">more_horiz</span>
        </button>
        </div>
    </div>
  );
};

KangaConnection.propTypes = {
  name: PropTypes.string.isRequired,
  isConnected: PropTypes.bool.isRequired,
  onConnect: PropTypes.func.isRequired,
  onDisconnect: PropTypes.func.isRequired,
};

export default KangaConnection;
