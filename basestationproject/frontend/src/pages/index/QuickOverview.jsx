
function QuickOverview(){
  return (
    <div className="quick-overview">
      <h3>Quick Overview</h3>
      <div className="function-grid">
        <div className="function-card">
          <p className="percentage">75%</p>
          <p>Performance</p>
        </div>
        <div className="function-card">
          <p className="percentage">60%</p>
          <p>Usage</p>
        </div>
        <div className="function-card">
          <p className="percentage">95%</p>
          <p>Efficiency</p>
        </div>
      </div>
    </div>
  );
};

export default QuickOverview;
