import React, { useEffect } from 'react';
import {Button, Container, Row, Col} from 'react-bootstrap';
import './LogHistory.css';

function LogHistory() {
  const [logs, setLogs] = useState([]); // State to store logs
  const [loading, setLoading] = useState(true); // To manage loading state
  const [error, setError] = useState(null); // To manage error state

  // Fetch logs from the backend when teh component mounts
  useEffect(() => {
    // Fetch with your actual API endpoint
    fetch('http://django_server:5000/api/logs')
      .then(response => response.json())
      .then(data => {
        setLogs(data); // Set logs to state
        setLoading(false); // Set loading to false
      })
      .catch(error => {
        setError(`Error fetching logs: ${error}.`);
        setLoading(false); // Set loading to false
      });
  }, []);  // Empty array ensures this runs once when the component mounts

  // If the data is still loading, show a loading message
  if (loading) {
    return (
      <Container className="log-history p-3">
        <Row>
          <Col>
            <h3 className='text-center mb-3'>Logs</h3>
            <p className='text-center'>Loading logs...</p>
          </Col>
        </Row>
      </Container>
    );
  }

  // If there was an error fetching the logs, show an error message
  if (error) {
    return (
      <Container className="log-history p-3">
        <Row>
          <Col>
            <h3 className='text-center mb-3'>Logs</h3>
            <p className='text-center'>Error fetching logs: {error}</p>
          </Col>
        </Row>
      </Container>
    );
  }

  
  // Render the logs once they have been fetched
  return (
    <Container className="log-history p-3">
      <Row>
        <Col>
          <h3 className='text-center mb-3'>Logs</h3>
          <div className="log-content bg-light p-3 rounded">
            {logs.map((log, index) => (
              <p key={index}>{log}</p>
            ))}
          </div>
        </Col>
      </Row>
      <Row>
        <Col class name="text-center"> 
          <Button variant="primary"className="download-btn">Download Log</Button>
        </Col>
      </Row>
    </Container>
  )
};

export default LogHistory;