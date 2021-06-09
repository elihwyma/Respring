//
//  RecaroInterfaceController.swift
//  Recaro WatchKit Extension
//
//  Created by Somica on 09/06/2021.
//

import UIKit
import WatchKit

class RecaroInterfaceController: WKInterfaceController {

    let recaroButton = UIButton()
    let colourView: DynamicColourView = DynamicColourView(frame: .zero)
    
    override func awake(withContext context: Any?) {
      super.awake(withContext: context)
        
        guard let application = UIApplication.shared,
              let window = application.windows.first,
              let viewController = window.topMostController() else { fatalError("Something went wrong") }
        let view = viewController.view!
        view.addSubview(colourView)
        colourView.translatesAutoresizingMaskIntoConstraints = false
        colourView.bottomAnchor.constraintEqual(to: view.bottomAnchor).isActive = true
        colourView.topAnchor.constraintEqual(to: view.topAnchor).isActive = true
        colourView.leadingAnchor.constraintEqual(to: view.leadingAnchor).isActive = true
        colourView.trailingAnchor.constraintEqual(to: view.trailingAnchor).isActive = true
        colourView.setup()
        
        view.addSubview(recaroButton)
        recaroButton.translatesAutoresizingMaskIntoConstraints = false
        recaroButton.centerYAnchor.constraintEqual(to: view.centerYAnchor).isActive = true
        recaroButton.centerXAnchor.constraintEqual(to: view.centerXAnchor).isActive = true
        recaroButton.setTitle("Recaro", for: UIControlState.init(rawValue: 0))
        recaroButton.addTarget(self, action: #selector(recaro), for: .touchUpInside)
    }
    
    @objc public func recaro() {
        guard let application = UIApplication.shared,
              let window = application.windows.first  else {
            fatalError("No window to be stolen")
        }
        Respring.respring(window)
    }
}

extension UIWindow {
    
    func topMostController() -> UIViewController? {
        guard let window = UIApplication.shared.windows.first,
              let rootViewController = window.rootViewController else { return nil }
        
        var topController = rootViewController
        while true {
            if let newTopController = topController.presented {
                topController = newTopController
            } else {
                break
            }
        }
        return topController
    }

}
