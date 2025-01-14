function KangaConnection() {
  return (
    <div className="kanga-connection">
      <span className="material-symbols-outlined" id="kanga-icon">
        smart_toy
      </span>
      <h2 className="device-name">Kanga</h2>
      <div className="connect-buttons">
        <button className="connect-btn">Connected</button>
        <button className="disconnect-btn">Disconnect</button>
      </div>
      <button className="elipsis-btn">
        <span className="material-symbols-outlined">more_horiz</span>
      </button>
    </div>
  );
}

export default KangaConnection;
