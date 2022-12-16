import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

public class Main {
    public static void main(String[] args) {
        //静态代理
        Server server = new Server();
        MyProxy proxy = new MyProxy(server);
        proxy.browse();

        //动态代理
        SuperMan man=new SuperMan();
        Human instance=(Human) ProxyFactory.getProxyInstance(man);
        System.out.println(instance.getBelief());
        instance.food("麻辣烫");
    }
}

//静态代理
interface NetWork {
    public void browse();
}

class Server implements NetWork {
    @Override
    public void browse() {
        System.out.println("真实的服务器访问网络");
    }
}

class MyProxy implements NetWork {
    private NetWork work;

    public MyProxy(NetWork work) {
        this.work = work;
    }

    @Override
    public void browse() {
        check();
        work.browse();
    }

    public void check() {
        System.out.println("联网之前的检查工作");
    }
}

//动态代理
interface Human{
    String getBelief();
    void food(String food);
}

class SuperMan implements Human{
    @Override
    public String getBelief() {
        return "I believe that I can fly";
    }

    @Override
    public void food(String food) {
        System.out.println("我喜欢吃"+food);
    }
}
class MyInvocationHandler implements InvocationHandler {
    private Object obj;//被代理类对象赋值

    public void bind(Object obj){
        this.obj=obj;
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        //method即为代理类对象调用的方法，也就作为了被代理类对象调用的方法
        Object returnValue=method.invoke(obj,args);
        return returnValue;
    }
}

class ProxyFactory{
    //返回一个代理类的对象
    public static Object getProxyInstance(Object obj){
        MyInvocationHandler handler=new MyInvocationHandler();
        return Proxy.newProxyInstance(obj.getClass().getClassLoader(), obj.getClass().getInterfaces(),handler);
    }
}