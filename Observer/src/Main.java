import java.util.ArrayList;
import java.util.Observable;
public class Main {
    public static void main(String[] args) {

    }
}

interface Observer {
    public void update(float temp, float humidity, float pressure);
}

interface Sub {
    public void registerObserver(Observer o);

    public void removeObserver(Observer o);

    public void notifyObserver();
}

interface DisplayElement {
    public void display();
}

class WeatherData implements Sub {
    private ArrayList observers;
    private float temp;
    private float humidity;
    private float pressure;

    public WeatherData() {
        observers = new ArrayList();
    }

    @Override
    public void registerObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        int i = observers.indexOf(o);
        if (i > 0) {
            observers.remove(o);
        }
    }

    @Override
    public void notifyObserver() {
        for (int i = 0; i < observers.size(); i++) {
            Observer observer = (Observer) observers.get(i);
            observer.update(temp, humidity, pressure);
        }
    }

    public void measurementsChanged() {
        notifyObserver();
    }

    public void setMeasurement(float temp, float humidity, float pressure) {
        this.temp = temp;
        this.humidity = humidity;
        this.pressure = pressure;
        measurementsChanged();
    }
}

class currentConditionDisplay implements DisplayElement, Observer {
    private float temp;
    private float humidity;
    private Sub weatherData;

    public currentConditionDisplay(Sub weatherData) {
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }

    @Override
    public void display() {
        System.out.println("Current conditions:" + temp + "F degrees and " + humidity + "% humidity");
    }

    @Override
    public void update(float temp, float humidity, float pressure) {
        this.temp = temp;
        this.humidity = humidity;
        display();
    }
}