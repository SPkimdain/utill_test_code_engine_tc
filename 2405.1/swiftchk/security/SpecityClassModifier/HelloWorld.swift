import UIKit
import Foundation
import EventKit


class ViewControllerParent {  //@violation
}

public class ViewController: UIViewController, UITextFieldDelegate, ViewControllerParent {

    var eventStore : EKEventStore!
    var calendar: EKCalendar!

    @IBOutlet weak var datePicker: UIDatePicker!
    @IBOutlet weak var textField: UITextField!
    @IBOutlet weak var eventCalendario: UITextField!
    @IBOutlet weak var titleEvent: UITextField!

    @IBAction func test (){



    var triNum: Float = 0.3 + 0.6 + 0.9
    var myNumber: Float = 0.3 + 0.6





    if myNumber == 0.9 { // Noncompliant. Because of floating point imprecision, this will be false
    // ...
    }

    if myNumber <= 0.9 && myNumber >= 0.9 { // Noncompliant indirect equality test
    // ...
    }

    if myNumber < 0.9 || myNumber > 0.9 { // Noncompliant indirect inequality test
    // ...
    }


    }

    @IBAction func saveCalendar(_ sender: UIButton) {
        let calendar = EKCalendar(for: EKEntityType.event, eventStore: eventStore)
        eventStore.requestAccess(to: EKEntityType.event, completion: {(granted,error) in
            if(granted == false){
                print("Access Denied")
            } else{
                var auxiliar = self.eventStore.sources
                calendar.source = auxiliar[0]
                calendar.title = self.textField.text!
                print(calendar.title)

                try! self.eventStore.saveCalendar(calendar, commit: true)
            }
        })
    }

    @IBAction func saveEvent(_ sender: UIButton) {
        eventStore.requestAccess(to: EKEntityType.event, completion: {(granted,error) in
            if(granted == false){
                print("Access Denied")
            }
            else{
                let arrayCalendars = self.eventStore.calendars(for: EKEntityType.event)
                var theCalendar: EKCalendar!
                for calendario in arrayCalendars{
                    if(calendario.title == self.eventCalendario.text){
                        theCalendar = calendario
                        print(theCalendar.title)
                    }
                }
                if(theCalendar != nil){
                    let event = EKEvent(eventStore: self.eventStore)
                    event.title = self.titleEvent.text!
                    event.startDate = self.datePicker.date
                    event.endDate = self.datePicker.date.addingTimeInterval(3600)
                    event.calendar = theCalendar
                    do {
                        try! self.eventStore.save(event, span: .thisEvent)
                        let alert = UIAlertController(title: "Calendar", message: "Event created \(event.title) in \(theCalendar.title)", preferredStyle: UIAlertControllerStyle.alert)
                        alert.addAction(UIAlertAction(title: "Accept", style: UIAlertActionStyle.default, handler: nil))
                        DispatchQueue.main.async(execute: { () -> Void in
                            self.present(alert, animated: true, completion: nil)
                        })
                    }
                }
                else{
                    print("No calendar with that name")
                }
            }
        })
    }



    override func viewDidLoad() {
        super.viewDidLoad()
        eventStore = EKEventStore()

        let tapGestureRecognizer : UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(ViewController.dismissKeyBoard))

        self.view.addGestureRecognizer(tapGestureRecognizer)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

    func dismissKeyBoard() {
        self.textField.resignFirstResponder()
    }

    func textFieldShouldReturn(_ textField: UITextField) -> Bool // called when 'return' key pressed. return NO to ignore.
    {
        textField.resignFirstResponder()
        return true;
    }

    //called when users tap out of textfield
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        self.view.endEditing(true)
    }

}




