package security;

import java.lang.ApApsCommonCodeVO;

public class Xss {
	@RequestMapping("/aps/common/makeCommonCode.do")
	public void makeCommonCode(HttpSession session, @ModelAttribute("apApsCommonCodeVO") ApApsCommonCodeVO apApsCommonCodeVO,
							   HttpServletRequest request, HttpServletResponse response,
							   ModelMap model) throws Exception {
		String target = apApsCommonCodeVO.getTarget();
		List resultList = apApsExcelService.selectCommonCode(apApsCommonCodeVO);
		JSONArray jsonArray = new JSONArray();
		jsonArray = JSONArray.fromObject(resultList);
		response.setContentType("text/xml;charset=utf-8");
		PrintWriter printWriter = response.getWriter();
		printWriter.print(target); // @violation
		printWriter.print(jsonArray.toString());
		printWriter.flush();
		printWriter.close();
	}
}
