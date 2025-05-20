#include "network.h"
#include <iostream>
#include <algorithm>
#include <cctype>  // for std::tolower

namespace bht {

// CSVReader implementation
CSVReader::CSVReader(const std::string& filePath) {
    file.open(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return;
    }
    parseHeaders();
}

void CSVReader::parseHeaders() {
    if (!file.good()) return;
    
    std::string headerLine;
    if (std::getline(file, headerLine)) {
        auto headerFields = parseLine(headerLine);
        for (size_t i = 0; i < headerFields.size(); ++i) {
            headers[headerFields[i]] = i;
        }
    }
}

std::vector<std::string> CSVReader::parseLine(const std::string& line) {
    std::vector<std::string> fields;
    bool inQuotes = false;
    std::string field;
    
    for (char c : line) {
        if (c == '"') {
            inQuotes = !inQuotes;
        } else if (c == ',' && !inQuotes) {
            fields.push_back(field);
            field.clear();
        } else {
            field += c;
        }
    }
    fields.push_back(field); // Add the last field
    
    return fields;
}

std::string CSVReader::getField(const std::string& key) {
    auto it = headers.find(key);
    if (it == headers.end() || it->second >= currentRow.size()) {
        return "";
    }
    return currentRow[it->second];
}

std::string CSVReader::getField(const std::string& key, const std::string& defaultValue) {
    std::string value = getField(key);
    return value.empty() ? defaultValue : value;
}

bool CSVReader::next() {
    if (!file.good()) return false;
    
    std::string line;
    if (std::getline(file, line)) {
        currentRow = parseLine(line);
        return true;
    }
    return false;
}

bool CSVReader::hasNext() {
    return file.good();
}

void CSVReader::reset() {
    file.clear();
    file.seekg(0);
    parseHeaders();
}

// Network implementation
Network::Network(const std::string& directoryPath) {
    loadAgencies(directoryPath);
    loadCalendarDates(directoryPath);
    loadCalendars(directoryPath);
    loadLevels(directoryPath);
    loadPathways(directoryPath);
    loadRoutes(directoryPath);
    loadShapes(directoryPath);
    loadStopTimes(directoryPath);
    loadStops(directoryPath);
    loadTransfers(directoryPath);
    loadTrips(directoryPath);
}

std::vector<Stop> Network::search(const std::string& searchTerm) {
    std::vector<Stop> results;

    // Convert search term to lowercase for case-insensitive comparison
    std::string lowerSearchTerm = searchTerm;
    std::transform(lowerSearchTerm.begin(), lowerSearchTerm.end(), lowerSearchTerm.begin(),
        [](unsigned char c) { return std::tolower(c); });

    // Search in stop names
    for (const auto& pair : stops) {
        const Stop& stop = pair.second;
        
        // Convert stop name to lowercase for case-insensitive comparison
        std::string lowerStopName = stop.name;
        std::transform(lowerStopName.begin(), lowerStopName.end(), lowerStopName.begin(),
            [](unsigned char c) { return std::tolower(c); });
        
        // Check if stop name contains the search term
        if (lowerStopName.find(lowerSearchTerm) != std::string::npos) {
            results.push_back(stop);
        }
    }

    return results;
}

// Utility methods
GTFSDate Network::parseDate(const std::string& dateStr) {
    GTFSDate date = {0, 0, 0};
    if (dateStr.length() >= 8) {
        date.year = std::stoi(dateStr.substr(0, 4));
        date.month = std::stoi(dateStr.substr(4, 2));
        date.day = std::stoi(dateStr.substr(6, 2));
    }
    return date;
}

GTFSTime Network::parseTime(const std::string& timeStr) {
    GTFSTime time = {0, 0, 0};
    
    if (timeStr.length() >= 8) {
        try {
            time.hour = std::stoi(timeStr.substr(0, 2));
            time.minute = std::stoi(timeStr.substr(3, 2));
            time.second = std::stoi(timeStr.substr(6, 2));
        } catch (...) {
            // Handle parsing errors
        }
    }
    
    return time;
}

// Implement all the loading methods with placeholder functionality
void Network::loadAgencies(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/agency.txt");
    while (reader.next()) {
        Agency agency;
        agency.id = reader.getField("agency_id");
        agency.name = reader.getField("agency_name");
        agency.url = reader.getField("agency_url");
        agency.timezone = reader.getField("agency_timezone");
        agency.language = reader.getField("agency_lang", "");
        agency.phone = reader.getField("agency_phone", "");
        
        agencies[agency.id] = agency;
    }
}

void Network::loadCalendarDates(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/calendar_dates.txt");
    while (reader.next()) {
        CalendarDate calendarDate;
        calendarDate.serviceId = reader.getField("service_id");
        calendarDate.date = parseDate(reader.getField("date"));
        calendarDate.exception = static_cast<CalendarDateException>(std::stoi(reader.getField("exception_type")));
        
        calendarDates.push_back(calendarDate);
    }
}

void Network::loadCalendars(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/calendar.txt");
    while (reader.next()) {
        Calendar calendar;
        calendar.serviceId = reader.getField("service_id");
        calendar.monday = static_cast<CalendarAvailability>(std::stoi(reader.getField("monday")));
        calendar.tuesday = static_cast<CalendarAvailability>(std::stoi(reader.getField("tuesday")));
        calendar.wednesday = static_cast<CalendarAvailability>(std::stoi(reader.getField("wednesday")));
        calendar.thursday = static_cast<CalendarAvailability>(std::stoi(reader.getField("thursday")));
        calendar.friday = static_cast<CalendarAvailability>(std::stoi(reader.getField("friday")));
        calendar.saturday = static_cast<CalendarAvailability>(std::stoi(reader.getField("saturday")));
        calendar.sunday = static_cast<CalendarAvailability>(std::stoi(reader.getField("sunday")));
        calendar.startDate = parseDate(reader.getField("start_date"));
        calendar.endDate = parseDate(reader.getField("end_date"));
        
        calendars[calendar.serviceId] = calendar;
    }
}

void Network::loadLevels(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/levels.txt");
    while (reader.next()) {
        Level level;
        level.id = reader.getField("level_id");
        level.index = std::stoi(reader.getField("level_index"));
        level.name = reader.getField("level_name", "");
        
        levels[level.id] = level;
    }
}

void Network::loadPathways(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/pathways.txt");
    while (reader.next()) {
        Pathway pathway;
        pathway.id = reader.getField("pathway_id");
        pathway.fromStopId = reader.getField("from_stop_id");
        pathway.toStopId = reader.getField("to_stop_id");
        pathway.mode = static_cast<PathwayMode>(std::stoi(reader.getField("pathway_mode")));
        pathway.isBidirectional = std::stoi(reader.getField("is_bidirectional")) != 0;
        pathway.length = std::stof(reader.getField("length", "0"));
        pathway.traversalTime = std::stoi(reader.getField("traversal_time", "0"));
        pathway.stairCount = std::stoi(reader.getField("stair_count", "0"));
        pathway.maxSlope = std::stof(reader.getField("max_slope", "0"));
        pathway.minWidth = std::stof(reader.getField("min_width", "0"));
        pathway.signpostedAs = reader.getField("signposted_as", "");
        
        pathways[pathway.id] = pathway;
    }
}

void Network::loadRoutes(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/routes.txt");
    while (reader.next()) {
        Route route;
        route.id = reader.getField("route_id");
        route.agencyId = reader.getField("agency_id", "");
        route.shortName = reader.getField("route_short_name", "");
        route.longName = reader.getField("route_long_name", "");
        route.description = reader.getField("route_desc", "");
        route.type = static_cast<RouteType>(std::stoi(reader.getField("route_type")));
        route.color = reader.getField("route_color", "");
        route.textColor = reader.getField("route_text_color", "");
        
        routes[route.id] = route;
    }
}

void Network::loadShapes(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/shapes.txt");
    while (reader.next()) {
        Shape shape;
        shape.id = reader.getField("shape_id");
        shape.latitude = std::stod(reader.getField("shape_pt_lat"));
        shape.longitude = std::stod(reader.getField("shape_pt_lon"));
        shape.sequence = std::stoi(reader.getField("shape_pt_sequence"));
        
        shapes.push_back(shape);
    }
}

void Network::loadStopTimes(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/stop_times.txt");
    while (reader.next()) {
        StopTime stopTime;
        stopTime.tripId = reader.getField("trip_id");
        stopTime.arrivalTime = parseTime(reader.getField("arrival_time"));
        stopTime.departureTime = parseTime(reader.getField("departure_time"));
        stopTime.stopId = reader.getField("stop_id");
        stopTime.stopSequence = std::stoi(reader.getField("stop_sequence"));
        stopTime.pickupType = static_cast<PickupType>(std::stoi(reader.getField("pickup_type", "0")));
        stopTime.dropOffType = static_cast<EDropOffType>(std::stoi(reader.getField("drop_off_type", "0")));
        stopTime.stopHeadsign = reader.getField("stop_headsign", "");
        
        stopTimes.push_back(stopTime);
    }
}

void Network::loadStops(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/stops.txt");
    while (reader.next()) {
        Stop stop;
        stop.id = reader.getField("stop_id");
        stop.code = reader.getField("stop_code", "");
        stop.name = reader.getField("stop_name", "");
        stop.description = reader.getField("stop_desc", "");
        stop.latitide = std::stod(reader.getField("stop_lat", "0"));
        stop.longitude = std::stod(reader.getField("stop_lon", "0"));
        stop.locationType = static_cast<LocationType>(std::stoi(reader.getField("location_type", "0")));
        stop.parentStation = reader.getField("parent_station", "");
        stop.wheelchairBoarding = static_cast<WheelchairAccessibility>(std::stoi(reader.getField("wheelchair_boarding", "0")));
        stop.platformCode = reader.getField("platform_code", "");
        stop.levelId = reader.getField("level_id", "");
        stop.zoneId = reader.getField("zone_id", "");
        
        stops[stop.id] = stop;
    }
}

void Network::loadTransfers(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/transfers.txt");
    while (reader.next()) {
        Transfer transfer;
        transfer.fromStopId = reader.getField("from_stop_id");
        transfer.toStopId = reader.getField("to_stop_id");
        transfer.fromRouteId = reader.getField("from_route_id", "");
        transfer.toRouteId = reader.getField("to_route_id", "");
        transfer.fromTripId = reader.getField("from_trip_id", "");
        transfer.toTripId = reader.getField("to_trip_id", "");
        transfer.type = static_cast<TransferType>(std::stoi(reader.getField("transfer_type")));
        transfer.minTransferTime = std::stoi(reader.getField("min_transfer_time", "0"));
        
        transfers.push_back(transfer);
    }
}

void Network::loadTrips(const std::string& directoryPath) {
    CSVReader reader(directoryPath + "/trips.txt");
    while (reader.next()) {
        Trip trip;
        trip.id = reader.getField("trip_id");
        trip.routeId = reader.getField("route_id");
        trip.serviceId = reader.getField("service_id");
        trip.headsign = reader.getField("trip_headsign", "");
        trip.shortName = reader.getField("trip_short_name", "");
        trip.direction = static_cast<TripDirection>(std::stoi(reader.getField("direction_id", "0")));
        trip.blockId = reader.getField("block_id", "");
        trip.shapeId = reader.getField("shape_id", "");
        trip.wheelchairAccessible = static_cast<WheelchairAccessibility>(std::stoi(reader.getField("wheelchair_accessible", "0")));
        trip.bikesAllowed = static_cast<BikesAllowed>(std::stoi(reader.getField("bikes_allowed", "0")));
        
        trips.push_back(trip);
    }
}

} // namespace bht