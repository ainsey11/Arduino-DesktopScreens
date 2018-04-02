from openhab import openHAB

OpenHabURL = "http://172.16.2.41:8880/rest"
openhab = openHAB(OpenHabURL)
item = openhab.get_item('weatherunderground_weather_9d9f927c_current_feelingTemperature')
print item.state
