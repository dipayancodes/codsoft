class ContactManager:
    def __init__(self):
        self.contacts = []

    def add_contact(self, name, phone, email, address):
        self.contacts.append({"name": name, "phone": phone, "email": email, "address": address})

    def view_contacts(self):
        for contact in self.contacts:
            print(f"Name: {contact['name']}, Phone: {contact['phone']}")

    def search_contact(self, search_term):
        results = [c for c in self.contacts if search_term.lower() in c['name'].lower() or search_term in c['phone']]
        if results:
            for contact in results:
                print(f"Name: {contact['name']}, Phone: {contact['phone']}, Email: {contact['email']}, Address: {contact['address']}")
        else:
            print("No contacts found.")

    def update_contact(self, name):
        contact = next((c for c in self.contacts if c['name'].lower() == name.lower()), None)
        if contact:
            contact['phone'] = input("Enter new phone number: ")
            contact['email'] = input("Enter new email: ")
            contact['address'] = input("Enter new address: ")
            print("Contact updated.")
        else:
            print("Contact not found.")

    def delete_contact(self, name):
        self.contacts = [c for c in self.contacts if c['name'].lower() != name.lower()]
        print("Contact deleted if it existed.")

def main():
    manager = ContactManager()
    while True:
        print("\n1. Add Contact\n2. View Contacts\n3. Search Contact\n4. Update Contact\n5. Delete Contact\n6. Exit")
        choice = input("Choose an option: ")

        if choice == "1":
            name = input("Enter name: ")
            phone = input("Enter phone number: ")
            email = input("Enter email: ")
            address = input("Enter address: ")
            manager.add_contact(name, phone, email, address)
        elif choice == "2":
            manager.view_contacts()
        elif choice == "3":
            search_term = input("Enter name or phone number to search: ")
            manager.search_contact(search_term)
        elif choice == "4":
            name = input("Enter the name of the contact to update: ")
            manager.update_contact(name)
        elif choice == "5":
            name = input("Enter the name of the contact to delete: ")
            manager.delete_contact(name)
        elif choice == "6":
            break
        else:
            print("Invalid choice, please try again.")

main()

