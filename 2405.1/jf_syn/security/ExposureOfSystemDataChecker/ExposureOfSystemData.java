package security;

import java.io.IOException;
import t.t.CustomException;
import java.lang.ClassCastException;

public class ExposureOfSystemData {
    public void f(Throwable t) {
        try {
            g();
        } catch (IOException e) {
            e.printStackTrace(); // @violation
            System.err.printf(e.getMessage()); // @violation
            System.err.println(e.getMessage()); // @violation
            System.err.printf(e); // @violation
        } catch (CustomException e) {
            e.printStackTrace(); /* Safe */
            System.err.printf(e.getMessage()); /* Safe */
            System.err.println(e.getMessage()); /* Safe */
            System.err.printf(e); /* Safe */
        } catch (ClassCastException | Exception e) {
            e.printStackTrace(); // @violation
            System.err.printf(e.getMessage()); // @violation
            System.err.println(e.getMessage()); // @violation
            System.err.printf(e); // @violation
        }
        t.printStackTrace(); // @violation
    }

    private void g() throws IOException {

    }
}