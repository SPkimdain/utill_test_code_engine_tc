
import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class StringMethod_CharAt {
	
	private static final long serialVersionUID = 1L;
	
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
	
		String param = request.getParameter("vector");

		if (param != null && param.length() > 1 && param.charAt(0) == 'a') {
			response.getWriter().write(param,0,param.length()); // guard: Eq(CharAt(getParameter("vector"), 0), 39)
		}
	}
}
