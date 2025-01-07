1) python manage.py runserver
2) uvicorn main:app --host 127.0.0.1 --port 8001
3) python command_listener.py

curl -X POST http://127.0.0.1:8000/api/publish-custom-message/ -H "Content-Type: application/json" -d '{"epoch_time": 1673032025, "data": "Hello from Django!", "flag": true}'

Overwritten epoch_time