# Define o diretório atual de forma compatível
PWD := $(shell pwd)

run:
	@uvicorn workout_api.main:app --reload

create-migrations:
	@PYTHONPATH=$(PWD) alembic revision --autogenerate -m "$(d)"

run-migrations:
	@PYTHONPATH=$(PWD) alembic upgrade head