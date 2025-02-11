import React from "react";
import PropTypes from "prop-types";
import "./DeviceDetails.css";

const DeviceDetails = ({ device }) => {
  return (
    <div className="device-details">
        <h3 className='device-name'>{device.name}</h3>
        <div className='device-data'>
          <div className='device-item'>
            <p className='data-value'>{device.battery}%</p>
            <p className='data-desc'>Battery</p>
          </div>
          <div classname="data-item">
            <p className='data-value'>{device.status}</p>
            <p className='data-desc'>Status</p>
          </div>
        </div>
    </div>
  );
};

DeviceDetails.propTypes = {
  device: PropTypes.shape({
    name: PropTypes.string.isRequired,
    battery: PropTypes.number.isRequired,
    status: PropTypes.string.isRequired,
  }).isRequired
};

export default DeviceDetails;
