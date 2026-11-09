FROM gcc:latest
WORKDIR /app
COPY . /app
RUN g++ -o inventory_app main.cpp
CMD ["./inventory_app"]
