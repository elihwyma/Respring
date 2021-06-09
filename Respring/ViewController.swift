//
//  ViewController.swift
//  Respring
//
//  Created by Somica on 09/06/2021.
//

import UIKit

class ViewController: UIViewController {
    
    let respring: UIButton = UIButton()
    let colourView: DynamicColourView = DynamicColourView(frame: .zero)
    private var isFired = false
    
    override var prefersStatusBarHidden: Bool {
        return isFired
    }
    
    override func viewDidLoad() {
        // Do any additional setup after loading the view.
        
        super.viewDidLoad()
        view.addSubview(colourView)
        colourView.translatesAutoresizingMaskIntoConstraints = false
        colourView.bottomAnchor.constraint(equalTo: view.bottomAnchor).isActive = true
        colourView.topAnchor.constraint(equalTo: view.topAnchor).isActive = true
        colourView.leadingAnchor.constraint(equalTo: view.leadingAnchor).isActive = true
        colourView.trailingAnchor.constraint(equalTo: view.trailingAnchor).isActive = true
        colourView.setup()
        view.addSubview(respring)
        respring.translatesAutoresizingMaskIntoConstraints = false
        respring.centerXAnchor.constraint(equalTo: view.centerXAnchor).isActive = true
        respring.centerYAnchor.constraint(equalTo: view.centerYAnchor).isActive = true
        respring.setTitle("Respring Device", for: .normal)
        respring.addTarget(self, action: #selector(respringDevice), for: .touchUpInside)
    }

    @objc public func respringDevice() {
        isFired = true
        setNeedsStatusBarAppearanceUpdate()
        guard let window = UIApplication.shared.windows.first else { return }
        Respring.respring(window)
    }
    
}

