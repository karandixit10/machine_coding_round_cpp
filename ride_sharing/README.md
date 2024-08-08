# Ride-Sharing Application

## Description

This is a ride-sharing application that allows users to offer and consume shared rides on a specified route. Users can search and select from multiple available rides based on criteria such as preferred vehicle type and the number of available seats.

## Features

- User onboarding
- Adding vehicle details for users
- Offering a shared ride on a route
- Selecting a ride from multiple offered rides using a selection strategy
- Ending a ride
- Viewing ride statistics
- Supporting multi-ride journeys if direct routes are unavailable

## Requirements

- The application should allow user onboarding.
- Users can offer a shared ride with details such as vehicle, origin, destination, and available seats.
- Users can select a ride from multiple offered rides based on preferred vehicle or most vacant seats.
- The system should be able to end a ride.
- Users can only offer a ride for a given vehicle once there are no active rides for that vehicle.
- View total rides offered/taken by all users.
- Support for multi-ride journeys when direct routes are unavailable.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/ridesharing-app.git
    ```
2. Navigate to the project directory:
    ```bash
    cd ridesharing-app
    ```
3. Run the application:
    ```bash
    python main.py
    ```

## Usage

### Onboard Users

```python
add_user("Rohan, M, 36")
add_vehicle("Rohan, Swift, KA-01-12345")

add_user("Shashank, M, 29")
add_vehicle("Shashank, Baleno, TS-05-62395")

add_user("Nandini, F, 29")

add_user("Shipra, F, 27")
add_vehicle("Shipra", "Polo, KA-05-41491")
add_vehicle("Shipra", "Activa, KA-12-12332")

add_user("Gaurav, M, 29")

add_user("Rahul, M, 35")
add_vehicle("Rahul", "XUV, KA-05-1234")
