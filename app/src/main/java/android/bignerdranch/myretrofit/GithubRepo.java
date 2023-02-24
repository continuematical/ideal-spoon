package android.bignerdranch.myretrofit;

public class GithubRepo {
    private int ID;
    private String name;
    private String email;
    private int age;
    private String[] topics;

    public GithubRepo(String name, String email, int age, String[] topics) {
        this.name = name;
        this.email = email;
        this.age = age;
        this.topics = topics;
    }

    public int getID() {
        return ID;
    }
}
