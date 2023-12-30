package com.example.tiktok.utils;


import io.reactivex.rxjava3.subjects.PublishSubject;
import io.reactivex.rxjava3.subjects.Subject;
import io.reactivex.rxjava3.core.Observable;

/**
 * RxBus管理类
 */
public class RxBus {
    private static volatile RxBus instance;
    private Subject<Object> bus;

    private RxBus() {
        //PublishSubject用于将事件传入多个观察者
        //转化为线程安全
        bus = PublishSubject.create().toSerialized();
    }

    public static RxBus getInstance() {
        if (instance == null) {
            synchronized (RxBus.class) {
                instance = new RxBus();
            }
        }
        return instance;
    }

    /**
     * 发送事件
     */
    public void post(Object object) {
        bus.onNext(object);
    }

    /**
     * 接收事件
     */
    public <T> Observable toObservable(Class<T> eventType) {
        return bus
                //过滤出特定类型的事件
                .filter(event -> eventType.isInstance(event))
                //将事件转化为指定类型
                .cast(eventType);
    }
}
