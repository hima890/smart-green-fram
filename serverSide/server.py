import datetime
from datetime import timedelta 
import random
import flask
from flask import request, jsonify


app = flask.Flask(__name__)


@app.route('/', methods=['GET'])
def home():
    return "Greting from the server"


@app.route('/api/v1/newInfo', methods=['GET'])
def api_all():
    x = random.randint(0, 1)
    y = random.randint(0, 1)

    strDataTime = datetime.datetime.now().strftime("%b %d %Y ")
    DateTime = datetime.datetime.now()
    time = datetime.datetime.now().strftime("%H:%M:%S")

    initialInTemp = 24
    initialOutTemp = 33

    initialSunShineIn = 4.3
    initialSunShineOut = 3.2

    initialCo2In = 3.9
    initialCo2Out = 2.3


    initialInTemp = str(initialInTemp - x)
    initialOutTemp = str(initialOutTemp - y)

    initialSunShineIn = str(round(initialSunShineIn - x, 1))
    initialSunShineOut = str(round(initialSunShineOut - y, 1))

    initialCo2In = str(round(initialCo2In - x, 1))
    initialCo2Out = str(round(initialCo2Out - y, 1))

    nextWaterTime = DateTime + timedelta(days=1)


            
    newInfo = {
            "timeKnow" : time,
            "datetime" : strDataTime,
            "initialInTemp" : initialInTemp,
            "initialOutTemp" : initialOutTemp,
            "initialSunShineIn" : initialSunShineIn,
            "initialSunShineOut" : initialSunShineOut,
            "initialCo2In" : initialCo2In,
            "initialCo2Out" : initialCo2Out,
            "nextWaterTime" : nextWaterTime
        }


    print(newInfo)

    return jsonify(newInfo)




app.config["DEBUG"] = True
app.run()