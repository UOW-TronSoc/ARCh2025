import React, { useState, useEffect } from "react";

const CameraFeed = () => {
  const [activeCameras, setActiveCameras] = useState([false, false, false, false]);
  const [imageSrcs, setImageSrcs] = useState(["", "", "", ""]);

  useEffect(() => {
    const intervals = activeCameras.map((isActive, index) => {
      if (isActive) {
        return setInterval(() => {
          setImageSrcs((prevSrcs) => {
            const newSrcs = [...prevSrcs];
            newSrcs[index] = `http://localhost:8000/api/video_feed/${index}/?time=${new Date().getTime()}`;
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
    <div>
      <h2>Live Camera Feeds</h2>
      <div style={{ display: "flex", flexWrap: "wrap" }}>
        {[0, 1, 2, 3].map((cameraId) => (
          <div key={cameraId} style={{ margin: "10px" }}>
            <button onClick={() => toggleCamera(cameraId)}>
              {activeCameras[cameraId] ? "Turn Off" : "Turn On"} Camera {cameraId}
            </button>
            {activeCameras[cameraId] && (
              <img
                src={imageSrcs[cameraId]}
                alt={`Camera ${cameraId}`}
                style={{ width: "320px", height: "240px", border: "2px solid black" }}
              />
            )}
          </div>
        ))}
      </div>
    </div>
  );
};

export default CameraFeed;
