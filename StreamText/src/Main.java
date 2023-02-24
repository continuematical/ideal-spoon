import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Stream<Locale> availableLocales = Stream.of(Locale.getAvailableLocales());
        Map<String, List<Locale>> collect = availableLocales.collect(Collectors.groupingBy(Locale::getDisplayCountry));
    }
}