<?PHP
 if (isset($_POST ["file"]))
 {
   $FileName = $File = $_POST ["file"];
 }
 else
 {
   $FileName = "";
 }
?>

<HTML>
<head>
<script type="text/javascript">
  forbidden();  //@violation
  document.write("Hello World!");
</script>
</head>
<BODY BGCOLOR=#FFFFFF>

<FORM ACTION=/cgi-bin/cgiwrap/username/Example.php METHOD=POST>

<P>Enter FileName:
<?PHP
  echo " <INPUT TYPE=TEXT NAME=file VALUE=\"$FileName\" SIZE=75>\n";
?>
<P><BR><P>
<INPUT TYPE=SUBMIT VALUE="Show Me!">

</FORM>

<P><BR><P>
<P><BR><P>
<P><BR><P>

<?PHP
 if (isset($File))
 {
   $Handle = @fopen ($File, "r"); // '@' suppresses external errors

   if ($Handle)
   {
     $FileText = fread ($Handle, 10000); // Read up to 10,000 Bytes

     fclose ($Handle);

     // Fix HTML tags that may be there

     $SafeText1 = str_replace ("&", "&amp;", $FileText);
     $SafeText2 = str_replace ("<", "&lt;", $SafeText1);
     $SafeText  = str_replace (">", "&gt;", $SafeText2);

     // Now it is safe to display it

     echo " <H2 ALIGN=CENTER>File: $File</H2>\n";

     echo "<PRE>\n";
     echo $SafeText;
     echo "</PRE>\n";
   }
   else
   {
     echo " <H3>Error: File '$File' is not accessible.</H3>\n";
   }
 }
?>

</BODY>
</HTML>