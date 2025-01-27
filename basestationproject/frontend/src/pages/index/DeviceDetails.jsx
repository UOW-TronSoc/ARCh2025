import './index2.css'

function DeviceDetails(){
  return (
    <div className="device-details">
      <h3 className="device-name">Device Name</h3>
      <div className="device-data">
        <div className="data-item">
          <p className="data-value">85%</p>
          <p className="data-desc">Battery</p>
        </div>
        <div className="data-item">
          <p className="data-value">Online</p>
          <p className="data-desc">Status</p>
        </div>
      </div>
    </div>
  );
};

export default DeviceDetails;
