
Module Module1

    Sub Main()
        Try
            Process.Start("http://www.fasoo.com")
        Catch ex As Exception
            MsgBox(ex.Message) '@violation
        End Try




    End Sub

End Module
