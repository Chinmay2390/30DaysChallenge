import heapq

class Flight:
    def __init__(self, source, destination, departure, arrival, price):
        self.source = source
        self.destination = destination
        self.departure = parse_time(departure)
        self.arrival = parse_time(arrival)
        self.price = price

def parse_time(time_str):
    hour = int(time_str[:2])
    minute = int(time_str[3:5])
    meridian = time_str[5:].strip()
    
    if meridian == "Am" and hour == 12:
        hour = 0
    elif meridian == "Pm" and hour != 12:
        hour += 12
    
    return hour * 60 + minute

def find_cheapest_flight():
    num_flights = int(input())
    flights = []
    flight_map = {}

    # Read all flight details
    for _ in range(num_flights):
        source, dest, departure, arrival, price = input().split()
        price = int(price)
        flight = Flight(source, dest, departure, arrival, price)
        flights.append(flight)
        if source not in flight_map:
            flight_map[source] = []
        flight_map[source].append(flight)

    # Read start and end locations and time constraints
    start, end = input().split()
    earliest_departure, latest_arrival = input().split()
    earliest_departure = parse_time(earliest_departure)
    latest_arrival = parse_time(latest_arrival)

    # Priority queue for Dijkstra's algorithm
    queue = []
    for flight in flight_map.get(start, []):
        if flight.departure >= earliest_departure and flight.arrival <= latest_arrival:
            heapq.heappush(queue, (flight.price, flight.arrival, flight.destination))

    min_cost = {}
    arrival_time = {}

    # Perform Dijkstra's algorithm to find the cheapest flight
    while queue:
        cost, current_arrival, city = heapq.heappop(queue)
        
        if city in min_cost and (cost > min_cost[city] or (cost == min_cost[city] and current_arrival >= arrival_time[city])):
            continue
        
        min_cost[city] = cost
        arrival_time[city] = current_arrival

        if city == end:
            print(cost)
            return

        for flight in flight_map.get(city, []):
            if flight.departure >= current_arrival and flight.departure >= earliest_departure and flight.arrival <= latest_arrival:
                heapq.heappush(queue, (cost + flight.price, flight.arrival, flight.destination))
    
    print("Impossible")

if __name__ == "__main__":
    find_cheapest_flight()
