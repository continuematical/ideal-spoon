package android.bignerdranch.shmily;

import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.UUID;

public class NewDay {
    private UUID uuid;
    private String name;
    private Date date;
    private int isReminder = 0;
    private int isTop = 0;


    public NewDay() {
        this(UUID.randomUUID());
    }

    public NewDay(UUID uuid) {
        this.uuid = uuid;
        date = new Date();
    }

    public UUID getUuid() {
        return uuid;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public int getReminder() {
        return isReminder;
    }

    public void setReminder(int reminder) {
        isReminder = reminder;
    }

    public int getTop() {
        return isTop;
    }

    public void setTop(int top) {
        isTop = top;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long calculateTime() {
        Calendar fromCalender = Calendar.getInstance();
        fromCalender.setTime(this.getDate());
        Calendar nowCalendar = Calendar.getInstance();
        nowCalendar.setTime(getTimeNow());
        long number = (fromCalender.getTimeInMillis() - nowCalendar.getTimeInMillis()) / (1000 * 3600 * 24);
        if (number < 0) {
            if (isLeapYear(System.currentTimeMillis() / (1000 * 3600 * 24))) {
                number += 366;
            } else {
                number += 365;
            }
        }
        return number;
    }

    public static Date getTimeNow(){
        Calendar nowCalendar = Calendar.getInstance();
        int year = nowCalendar.get(Calendar.YEAR);
        int month = nowCalendar.get(Calendar.MONTH);
        int dayOfMonth = nowCalendar.get(Calendar.DAY_OF_MONTH);
        Date now = new GregorianCalendar(year, month, dayOfMonth).getTime();
        return now;
    }

    public boolean isLeapYear(long year) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            return true;
        } else {
            return false;
        }
    }
}
