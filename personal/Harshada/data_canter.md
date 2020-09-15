         DATA CENTER ARCHITECTURE

3 Tier Software Architecture:

  - It is a client-server Software architecture platform
  - in which user interface (presentation), functional process logic (business rules), computer data storage and data access are developed and maintained independent module, most often on seperate module.
  - It allow any one of the 3  tires to be upgraded or replaces independently

  3 tiers in 3 Tire Architecture
      1. Presentation tier
      2. Application tier
      3. Data tier

  Presentation Tier:
    - It ocuupies top level / front end layer of architecture
    - consists of user interface which is accessible through a web browser
    - displays information and content useful to an end user and related to services available on a website
    - it communicates with other tires by sending result to the web browser and other tires in the network
    - This tier is build on web technologies such as HTML5, javascript, CSS or other web development framework
    - It communicates with other layers with API calls

  Application Tier:
    - Also calles as middle tier/ logic tier/ business tier
    - Controls Application functionality by performing datailed procing
    - contains functional business logic
    - Written in Java, .NET, C#, C++ etc

  Data Tier:
    - Data in this tier is kept independent of business logic
    - It contains data storage system and data acces layer
    - Data accessed by the Application Layer via API calls
    - eg. Mongodb, MySQL, Oracl, Microsoft SQL server etc

SAN:

  - Storage Area Network
  - It Is a dedicates high speed Network
  - In this Only Storage devices are connected to each other
  - Shared pools are available to servers
  - this can be a solution for upgrading storage and using available memory
  - Storage devices and server are connect using switches and fiber optic cable
  - HBA (Host Bust Adapter):
      - It is like a card
      - And installes on both servers and storage devices so they can acces each other through switches
      - It act like transreciver
      - Used to create a communication between servers and storage devices

NAS:

  - Network Attaches Storage
  - It is a specialised server which provides strage service
  - It is a computer/server which provides data storage services
  - Can be directly attaches to computer network
  - It provides storage sevice to the computer/devices in a Network
  - It is managed using IP address
  - It contains more than one hard disks which are logically configured to get more redundancy
  - Usually it is managed, configured and controled over the network using web browsers/ web based applications
  - 
