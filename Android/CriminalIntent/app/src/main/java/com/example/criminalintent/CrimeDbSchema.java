package com.example.criminalintent;

public class CrimeDbSchema {
    public static final class CrimeTable{
        //数据库表名
        public static final String Name="crimes";
        //定义数据库字段
        public static final class Cols{
            public static final String UUID="uuid";
            public static final String TITLE="title";
            public static final String DATE="date";
            public static final String SOLVED="solved";
            public static final String SUSPECT="suspect";
        }
    }
}
