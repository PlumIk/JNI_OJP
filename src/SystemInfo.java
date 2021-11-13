public class SystemInfo {
    native String get_info();//Declaring the native function

    static
    {
        System.loadLibrary("informer");
    }

    public static void main(String args[])
    {
        SystemInfo obj = new SystemInfo();
        System.out.println( obj.get_info());
    }
}
