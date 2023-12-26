package com.example.rxjavasample;

import io.reactivex.rxjava3.subjects.Subject;

/**
 * 创建RxBus操作类
 */
public class RxBus {
    private static volatile RxBus instance;
    private Subject<Object> bus;

    private RxBus() {

    }
}
