
//饿汉模式
//这种方式在类加载时就完成了初始化，所以类加载较慢，但获取对象的速度快。
// 这种方式基于类加载机制避免了多线程的同步问题，但是也不能确定有其他的方式（或者其他的静态方法）导致类装载，
// 这时候初始化instance显然没有达到懒加载的效果。
/*
public class Singleton {
    private static Singleton instance = new Singleton();
    private Singleton()
    {

    }
    public static Singleton getInstance() {
        return instance;
    }
}
 */
//懒汉模式（线程不安全）
//懒汉模式申明了一个静态对象，在用户第一次调用时初始化，虽然节约了资源，但第一次加载时需要实例化，反映稍慢一些，而且在多线程不能正常工作。
/*
public class Singleton {
    private static Singleton instance;
    private Singleton()
    {

    }
    public static Singleton getInstance() {
        if(instance==null)
        {
            instance = new Singleton();
        }
        return instance;
    }
}*/
//懒汉模式（线程安全）
//这种写法能够在多线程中很好的工作，但是每次调用getInstance方法时都需要进行同步，
// 造成不必要的同步开销，而且大部分时候我们是用不到同步的，所以不建议用这种模式。
/*public class Singleton {
    private static Singleton instance;
    private Singleton()
    {

    }
    public static synchronized Singleton getInstance() {
        if(instance==null)
        {
            instance = new Singleton();
        }
        return instance;
    }
}*/

//双重检查模式 （DCL）
/*
public class Singleton{
    private volatile static Singleton instance;
    private Singleton()
    {

    }
    public static Singleton getInstance()
    {
        if (instance == null)
        {
            synchronized (Singleton.class)
            {
                if (instance == null) {
                    instance = new Singleton();
                }
            }

        }
        return instance;
    }
}
*/
//静态内部类单例模式(推荐)
//第一次加载Singleton类时并不会初始化sInstance，
// 只有第一次调用getInstance方法时虚拟机加载SingletonHolder 并初始化sInstance ，
// 这样不仅能确保线程安全也能保证Singleton类的唯一性，所以推荐使用静态内部类单例模式。
public class Singleton {
    private Singleton()
    {

    }
    public static Singleton getInstance()
    {
        return SingletonHolder.sInstance;
    }
    private static class SingletonHolder {
        private static final Singleton sInstance = new Singleton();
    }
}
