
function NLISection() {
  return (
    <div className="nli-section">
      <h3>Natural Language Interface</h3>
      <div className="nli-content">
        <p className="user-command">
          <span>/YOU:</span> Show me obstacle avoidance model.
        </p>
        <p className="response">Creating cognitive map...</p>
      </div>
      <div className="nli-input">
        <input type="text" placeholder="Enter command..." />
        <button className="send-button">↩</button>
      </div>
    </div>
  );
}

export default NLISection;
