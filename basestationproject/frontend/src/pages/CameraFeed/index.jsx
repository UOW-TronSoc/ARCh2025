import React, { useState, useEffect } from "react";
import "bootstrap/dist/css/bootstrap.min.css"; // Import Bootstrap CSS
import './styles.css'

const CameraFeed = () => {
  const [activeCameras, setActiveCameras] = useState([false, false, false, false]);
  const [imageSrcs, setImageSrcs] = useState(["", "", "", ""]);

  useEffect(() => {
    document.title = "Camera Feed"
    const intervals = activeCameras.map((isActive, index) => {
      if (isActive) {
        return setInterval(() => {
          setImageSrcs((prevSrcs) => {
            const newSrcs = [...prevSrcs];
            newSrcs[index] = `http://django_server:8000/api/video_feed/${index}/?time=${new Date().getTime()}`;
            return newSrcs;
          });
        }, 100); // Refresh every 100ms
      }
      return null;
    });

    return () => {
      intervals.forEach((interval) => interval && clearInterval(interval));
    };
  }, [activeCameras]);

  const toggleCamera = (index) => {
    setActiveCameras((prev) => {
      const newActiveCameras = [...prev];
      newActiveCameras[index] = !newActiveCameras[index];
      return newActiveCameras;
    });
  };

  return (
    <div className="container mt-4 main-container">
      <h2 className="text-center text-white mb-4">Live Camera Feeds</h2>
      <div className="row">
        {[0, 1, 2, 3].map((cameraId) => (
          <div key={cameraId} className="col-md-6 d-flex flex-column align-items-center mb-4">
            <button 
              className={`btn ${activeCameras[cameraId] ? "btn-danger" : "btn-success"} mb-2`} 
              onClick={() => toggleCamera(cameraId)}
            >
              {activeCameras[cameraId] ? "Turn Off" : "Turn On"} Camera {cameraId}
            </button>
            {activeCameras[cameraId] && (
              <img
                src={imageSrcs[cameraId]}
                alt={`Camera ${cameraId}`}
                className="img-fluid border rounded"
                style={{ maxWidth: "100%", height: "auto" }}
              />
            )}
          </div>
        ))}
      </div>
    </div>
  );
};

export default CameraFeed;
