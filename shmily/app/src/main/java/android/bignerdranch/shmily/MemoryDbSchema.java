package android.bignerdranch.shmily;

public class MemoryDbSchema {
    public final static class PaperTable {
        public final static String PAPER_NAME = "papers";

        public static final class cols {
            public static final String UUID = "uuid_paper";
            public static final String TEXT = "text_paper";
            public static final String DATE = "date_paper";
            public static final String COLOR = "color_paper";
        }
    }

    public final static class InterestTable {
        public final static String INTEREST_NAME = "interests";

        public static final class cols {
            public static final String UUID = "uuid_interest";
            public static final String TITLE = "title_interest";
            public static final String TEXT = "text_interest";
            public static final String URI = "uri_interest";
        }
    }

    public final static class NewDayTable {
        public final static String DAY_NAME = "new_day";

        public static final class cols {
            public static final String UUID = "uuid_new_day";
            public static final String NAME = "name";
            public static final String DATE = "date";
            public static final String isReminder = "reminder";
            public static final String isTop = "top";
            public static final String topTime = "top_time";
        }
    }
}
