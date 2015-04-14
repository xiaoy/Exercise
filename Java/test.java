import java.io.*;
class test{
    public static void main(String[] args) throws IOException {
        DataInputStream d = new DataInputStream(new
                    FileInputStream("reginfo.txt"));
        int a = d.readInt();
        int b = d.readInt();
        int c = d.readInt();
        int e = d.readInt();
        boolean f = d.readBoolean();
        long g = d.readLong();
        boolean h = d.readBoolean();
        //String id = d.readUTF();
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(e);
        System.out.println(f);
        System.out.println(g);
        System.out.println(h);

        DataOutputStream out = new DataOutputStream(new
                    FileOutputStream("test.txt"));
        out.writeInt(2);
        out.writeInt(1);
        out.writeInt(51);
        out.writeInt(1);
        out.writeBoolean(true);
        out.writeLong(1375683407807L);
        out.writeBoolean(true);
        out.writeUTF("358574044515155");
    }
}
