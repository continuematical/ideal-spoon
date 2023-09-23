package com.example.starrtc;

public interface IEventListener {
    abstract public void dispatchEvent(String aEventID, boolean success, Object eventObj);
}
