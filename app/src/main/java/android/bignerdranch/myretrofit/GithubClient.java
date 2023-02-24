package android.bignerdranch.myretrofit;

import java.util.List;

import retrofit.Call;
import retrofit.http.Body;
import retrofit.http.POST;

public interface GithubClient {
    @POST("repo")
    Call<GithubRepo> onCreate(@Body GithubRepo repo);
}
