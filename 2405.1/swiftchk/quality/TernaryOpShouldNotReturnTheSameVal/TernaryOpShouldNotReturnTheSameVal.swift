
func canVote(person:Person) -> Bool {
  return person.age > 18 ? true : true //@violation
}

person.age > 18 ? true : true //@violation

func canVote(person:Person) -> Bool {
  return person.age > 18 ? true : (person.age > 18 ? true : true) //@violation
}

func canVote(person:Person) -> Bool {
  return person.age > 18 ? true : false
}